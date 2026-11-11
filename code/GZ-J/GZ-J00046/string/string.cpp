//ÀîéÈº­ GZ-J00046
#include<iostream>
using namespace std;
int n;
long long ans;
struct sb{
	long long a;
	char c;
}sk[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sk[i].a>>sk[i].c;
	}
	int p1=0,p2=n+1;
	long long c1=0,c2=0;
	while(1){
		if(!c1){
			++p1;
			c1=sk[p1].a;
		}
		if(!c2){
			--p2;
			c2=sk[p2].a;
		}
		if(p1>=p2)break;
		if(c1>=c2){
			c1-=c2;
			if(sk[p1].c!=sk[p2].c){
				ans+=c2;
			}
			c2=0;
		}
		else{
			c2-=c1;
			if(sk[p1].c!=sk[p2].c){
				ans+=c1;
			}
			c1=0;
		}
	}
	cout<<ans;
	return 0;
}
