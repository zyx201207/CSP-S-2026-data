#include<bits/stdc++.h>
using namespace std;
char s[20000000];
int k=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			k++;
			s[k]=c;
		}
	}
	char left=s[1];
	char right=s[n];
	int ans=0;
	int i=1;
	int j=n; 
	while(right>=left){
		if(left!=right){
			ans++;
			left=s[i++];
			right=s[j--];
			i=i+1;
			j=j-1;
		}
		else{
			left=s[i++];
			right=s[j--];
			i=i+1;
			j=j-1;
		}
	}
	cout<<ans;
	return 0;
} 
