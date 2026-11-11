#include<bits/stdc++.h>
using namespace std;
long long a,b[200005];
unsigned long long ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i]>>c[i];
	}
	for(int i=1,j=a;i<j;i++,j--){
		if(c[i]!=c[j]&&b[i]==b[j]){
			ans+=b[i];
			continue;
		}if(b[i]>b[j]&&c[i]!=c[j]){
			b[i]-=b[j];
			ans+=b[j];
			i--;
			continue;
		}if(b[j]>b[i]&&c[i]!=c[j]){
			b[j]-=b[i];
			ans+=b[i];
			j++;
			continue;
		}if(c[i]==c[j]){
			if(b[i]>b[j]){
				b[i]-=b[j];
				i--;
			}else if(b[j]>b[i]){
				b[j]-=b[i];
				j++;
			}
		}
	}cout<<ans;
	return 0;
} 
