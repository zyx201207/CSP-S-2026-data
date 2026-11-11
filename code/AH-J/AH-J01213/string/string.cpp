/*
Writer:AH-J01213
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,ans=0;
struct node{
	int a;
	char c;
}x[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>x[i].a>>x[i].c;
	}
	int left=1,right=n;
	while(left<right){
		int lcnt=0,rcnt=x[right].a;
//		if(x[left].a>x[right].a){
			lcnt=x[left].a;
			int change=x[right].c!=x[left].c?x[right].a:0;
			while((rcnt+x[right-1].a)<lcnt&&(right-1)>left){
				right--;
				rcnt+=x[right].a;
				if(x[right].c!=x[left].c){
					change+=x[right].a;
				}
			}
			if(rcnt<lcnt){
				right--;
				if(x[right].c!=x[left].c){
					change+=(lcnt-rcnt);
				}
				x[right].a-=(lcnt-rcnt);
				if(!x[right].a){
					right--;
				}
			}
			ans+=change;
			left++;
//		}
	}
	cout<<ans;
	return 0;
}

