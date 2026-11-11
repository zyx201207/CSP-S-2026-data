#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long m;
long long sum,cmt;
long long last;
long long a[500005];
long long b[500005];
long long qian;
int zuo;
void doing(){
	if(zuo==0){
		for(int i=1;i<n;i++){
			if(cmt>m){
				a[i-1]=last;
				return ;
			}
			cmt+=(a[i+1]-a[i])*i;
			last=a[i];
			a[i]=a[i+1];
			if(i>2) qian++ ;
		}
	}
	else{
		for(int i=zuo;i<n;i++){
		if(cmt>m){
			a[i-1]=last;
			return ;
		}
		cmt+=(a[i+1]-a[i])*i;
		last=a[i];
		a[i]=a[i+1];
		if(i>2) qian++ ;
 		}
	}
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f=a[1];
	bool checker=false;
	for(int i=1;i<=n;i++){
		if(checker){
			break;
		}
		if(f!=a[i]){
			checker=true;
		}
	}
	if(!checker){
		cout<<n<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	int maxx=-1e6;
	long long summ=0;
	for(int i=1;i<n;i++){
		summ+=a[n]-a[i];
	}
	if(summ<=m){
		cout<<n;
		return 0;
	}
	long long cha=0;
	for(int i=2;i<=n/2;i++){
		cha+=a[i]-a[i-1];
	} 
	long long chaa=0;
	for(int i=n/2+1;i<=n;i++){
		chaa+=a[i]-a[i-1];
	}
	if(cha>chaa) zuo=n/2;   
	doing();
	for(int i=1;i<=n;i++){
		if(a[i]==last) sum++;
	}
	cout<<sum+qian<<endl;
	return 0;
}
