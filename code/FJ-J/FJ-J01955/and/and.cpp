#include<bits/stdc++.h>
using namespace std;
const int Mn=2e5+5;
struct NODE{
	long long z;
	int one,zero,len;
	string s;
}a[Mn];
int n,m;
long long sum;
void cahfen(){
	for(int i=1;i<=n;i++){
		int b,c=0,maxx=-1;
		string ssq="";
		b=a[i].z;
		while(b>1){
			c++;
			ssq+=char(b%2+48);
			if(b%2==1){
				a[i].one++;
			}else{
				maxx=max(maxx,c);
			}
			b/=2;
		}
		c++;
		if(b==1)a[i].one++;
		else maxx=c;
		a[i].len=c;
		a[i].zero=maxx;
		ssq+=char(b+48); 
		a[i].s=ssq;
		for(int x=0;x<c;x++){
			a[i].s[x]=ssq[c-x-1];
		}
	}
}
bool cmp(NODE w,NODE v){
	if(w.len>v.len){
		return true;
	}else if(w.len<v.len){
		return false;
	}else{
		if(w.one>v.one){
			return true;
		}else if(w.one<v.one){
			return false;
		}else{
			if(w.zero<v.zero){
				return true;
			}else if(w.zero>v.zero){
				return false;
			}else{
				return false;
			}
		}
	}
}
int main(){
	freopen("and4.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].z; 
	}
	if(n<=10000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=max(sum,a[i].z&a[j].z);
			}
		}
		cout<<sum;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			sum=max(sum,a[i].z&a[i].z);
		}
		cout<<sum;
		return 0;
	}
	cahfen();
	sort(a+1,a+1+n,cmp);
	if(m==2){
		bool kj=true;
		int xy=1,yx=2;
		while(kj==true){
			if(abs(a[xy].z-a[yx].z)==1&&a[yx].zero==-1){
				xy++;
				yx++; 
			}else{
				sum=a[xy].z&a[yx].z;
				kj=false;
			}
		}
		cout<<sum;
		return 0;
	}
	sum=a[1].z;
	for(int i=2;i<=m;i++){
		sum=sum&a[i].z;
		cout<<sum<<" "<<a[i].z<<endl;
	}
	cout<<sum;
	return 0;
}

