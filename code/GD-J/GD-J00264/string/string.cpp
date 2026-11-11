#include<bits/stdc++.h>
using namespace std;
int N[200005];
char s[200005];
long long cnt;
int n;
long long ans;
int top;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>N[i]>>s[i];
		cnt+=N[i];
	}
	top=n;
	int ba=1;
	while(ba<=top){
		if(s[top]==s[ba]){
			if(N[top]>N[ba]){
				N[top]-=N[ba];
				ba++;
			}
			else if(N[top]==N[ba]){
				top--;
				ba++;
			}
			else{
				N[ba]-=N[top];
				top--;
			}
		}		
		else{
			if(N[top]>N[ba]){
				N[top]-=N[ba];
				ans+=N[ba];
				ba++;
			}
			else if(N[top]==N[ba]){
				top--;
				ans+=N[ba];
				ba++;
			}
			else{
				N[ba]-=N[top];
				ans+=N[top];
				top--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
