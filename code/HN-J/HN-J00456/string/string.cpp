#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
char s[N];
char a[N];
long long sum,n,m[100010],num,kl,fk;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
		cin>>n;
		
		for(long long i=1;i<=n;i++){
			cin>>m[i]>>s[i];
			for(long long j=num;j<num+m[i];j++){
				a[j]=s[i];
			}
			num+=m[i];
		}
		if(n==1){
			cout<<0;
			return 0;
		}
		kl=num-1;
		fk=num-1;
		if(num%2==0){
			for(long long i=0;i<num/2;i++){
		
					if(a[i]!=a[i+kl]){
						a[i+kl]=a[i];
						sum++;
						kl-=2;
					}else{
						sum+=0;
						kl-=2;
					}
					
				
			}
		}else{
			for(long long i=0;i<=num/2-1;i++){
		
					if(a[i]==a[i+fk]){
						fk-=2;
					}else{
						sum++;
							a[i+fk]=a[i];
					
						fk-=2;
					}
			}	
		}
	   cout<<sum;
	   return 0;
}
