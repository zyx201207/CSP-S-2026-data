#include<bits/stdc++.h>
using namespace std;
long long n,sss,andnum[20010],number;
char c;
long long ands(long long a,long long b){
	long long a2[20010],b2[20010],ansa2=0,ansb2=0;
	while(a){
		a2[++ansa2]+=a%2;
		a=(a-a%2)/2;
	}
	while(b){
		b2[++ansb2]+=b%2;
		b=(b-b%2)/2;
	}
	long long ans=0;
	ansa2=max(ansa2,ansb2);
	for(int i=ansa2;i>=1;i--){
		ans=ans*10;
		if(a2[i]==b2[i]){
			ans+=1;
		}
	}
	cout<<ans<<endl;
	long long num=0,i=0;
	while(ans){
		num+=ans%10*pow(2,i);
		ans=ans/10;
		i++;
	}
	return num;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>sss;
	for(int i=1;i<=n;i++){
		cin>>andnum[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			number=max(ands(andnum[i],andnum[j]),number);
//			cout<<number<<endl;
		}
	}
	cout<<number;
	return 0;
}
