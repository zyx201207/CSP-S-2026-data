#include<bits/stdc++.h>
using namespace std;

int n,l=0;
long long sum=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		int a;
		char c;
		scanf("%d",&a); 
		cin>>c; 
		for(int i=l+1;i<=l+a;i++)
			s[i] = c;
		l+=a;
	}  
	for(int i=1;i<=l/2;i++)
		for(int j=l;j>=l/2+2;j--)
			if(s[i]!=s[j]){
				sum++;
				break;
			}
	printf("%lld",sum);
	return 0;
}
