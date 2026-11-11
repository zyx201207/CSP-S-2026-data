//GZ-J00308  °×ğØºşĞ¡Ñ§Îâ³¿êØ 
#include <bits/stdc++.h>
using namespace std;
int a[100000005];
string s[105];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		for(int i = 1;i<=n;i++){
			if(s[i]==s[i+1]){
				cout<<0;
				return 0;
			}else{
				cout<<a[i];
				return 0;
			}
		}
	}
	long long sum = 0,cnt =0;
	if(n%2==0){
		for(int i = 1;i<=n/2;i++){
			for(int j = n;j>=n/2+1;j--){
				if(s[i]!=s[j]){
					sum+=a[i];
				}
			}
		}
		cout<<sum;
		return 0;
	}else{
		for(int i = 1;i<=n/2;i++){
			for(int j = n;j>=n/2+2;j--){
				if(s[i]!=s[j]){
					cnt+=a[i];
				}
			}
		}
		cout<<cnt;
		return 0;
	}
	cout<<0;
    return 0;
}

