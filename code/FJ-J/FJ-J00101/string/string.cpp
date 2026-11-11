#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN=2e5+5;

struct node{
	int L,R;
	char c;
}q[MAXN];

int n,num[MAXN];
ll len,ans;
char c[MAXN];
string s; 

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		len+=num[i];
		cin>>c[i];
		for(int j=1;j<=num[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
} 
