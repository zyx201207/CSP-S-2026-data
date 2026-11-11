#include<bits/stdc++.h>
using namespace std;
#define _for(i,x,y,z) for(int i=x;i<=y;i+=z)
typedef long long ll;
const int N=3e5+5;
ll ans;
int n;
int size[N];
char c[N];
int head,tail;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	_for(i,1,n,1){
		cin>>size[i]>>c[i];
	}head=1,tail=n;
	while(head<tail){
		if(size[head]<size[tail]){
			if(c[tail]!=c[head])ans+=size[head];
			size[tail]-=size[head];
			head++;
		}else if(size[head]>size[tail]){
			if(c[tail]!=c[head])ans+=size[tail];
			size[head]-=size[tail];
			tail--;
		}else{
			if(c[head]!=c[tail])ans+=size[head];
			head++,tail--;
		}
	}cout<<ans;
}
