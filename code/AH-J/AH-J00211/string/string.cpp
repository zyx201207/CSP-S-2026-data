#include<bits/stdc++.h>
using namespace std;
long long int n,k,b[4000000],head,tail,ans;
char c,d[4000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>c;
		b[i]=k;
		d[i]=c;
	}
	head=1;
	tail=n;
	if(n%2==1){
		while(head!=tail){
			if(d[head]!=d[tail]){
				ans+=min(b[head],b[tail]);
			}
			head++;
			tail--;
		}
		cout<<ans;
		return 0;
	}
	if(n%2==0){
		if(d[n/2]==d[n/2+1]){
			while(head!=tail-1){
				if(d[head]!=d[tail]){
					ans+=min(b[head],b[tail]);
				}
				head++;
				tail--;
			}
			cout<<ans;
			return 0;
		}
		else{
			while(head!=tail-1){
				if(d[head]!=d[tail]){
					ans+=min(b[head],b[tail]);
				}
				head++;
				tail--;
			}
			ans+=min(b[n/2],b[n/2+1]);
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
