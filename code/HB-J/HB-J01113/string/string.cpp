#include<bits/stdc++.h>
using namespace std;
string a;
char c[200005];
long long n,b[200005],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i];
		for(int j=1;j<=b[i];j++){
			a+=c;
		}
	}
	int i=1,j=n;
	while(j>i){
		if(b[i]>=b[j]){
			if(c[i]==c[j]){
				b[i]-=b[j];
				b[j]=0;
			}else{
				ans+=b[j];
				b[i]-=b[j];
				b[j]=0;
			}
		}else{
			if(c[i]==c[j]){
				b[j]-=b[i];
				b[i]=0;
			}else{
				ans+=b[i];
				b[j]-=b[i];
				b[i]=0;
			}
		}if(b[j]==0){
			j--;
		}if(b[i]==0){
			i++;
		}
	}
	cout<<ans;
	return 0;
}
