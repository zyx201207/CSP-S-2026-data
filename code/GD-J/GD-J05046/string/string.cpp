#include<bits/stdc++.h>
using namespace std;
string s;
int b[200005];
long long a[200005],ans,zc;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		b[i]=c;
		zc+=a[i];
	}
	long long i=1,j=n;
	long long a1=a[1],a2=a[n];
	long long b1=b[i],b2=b[n];
	long long ans1=a[1],ans2=a[n];
	for(;;){

		if(a1==0){
			i++;
			a1=a[i];
			b1=b[i];
			ans1+=a[i];
		}
		if(a2==0){
			j--;
			a2=a[j];
			b2=b[j];
			ans2+=a[j];
		}		
		if(ans1>(zc/2)){
			ans1=zc/2;
		}
		if(ans2>(zc/2)){
			ans2=zc/2;
		}
		if(b1==b2){
			int sth=min(a1,a2);
			a1-=sth;
			a2-=sth;
		}else{
			int sth=min(a1,a2);
			ans+=sth;
			a1-=sth;
			a2-=sth;
		}
		if(ans1==zc/2&&ans2==zc/2)break;
	}
	cout<<ans;
	return 0; 
} 
