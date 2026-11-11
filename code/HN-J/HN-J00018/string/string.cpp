#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s;
long long ans=0;
struct Node{
	long long a;
	char c;
}f[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>f[i].a>>f[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(f[l].c==f[r].c){
			if(f[l].a<f[r].a){
				f[r].a-=f[l].a;
				l++;
			}
			else{
				f[l].a-=f[r].a;
				r--;
			}
		}
		else{
			if(f[l].a<f[r].a){
				f[r].a-=f[l].a;
				ans+=f[l].a;
				l++;
			}
			else{
				ans+=f[r].a;
				f[l].a-=f[r].a;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
