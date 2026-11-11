#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
struct node{
	int x;
	char c;
}d[200005];
signed main(){
	freopen("string.in","r",stdin); freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>d[i].x>>d[i].c;
	}
	int mid=n/2;
	for(int i=0,j=n-1;i<=mid&&j>=mid;i++,j--){
        if(d[i].c!=d[j].c){
            if(d[i].x>=d[j].x){
                cnt+=d[j].x;
                d[i].x-=d[j].x;
                i--;
            }else if(d[i].x<d[j].x){
                cnt+=d[i].x;
                d[j].x-=d[i].x;
                j++;
            }
        }else {
            d[i].x=abs(d[i].x-d[j].x);
            i--;
        }

	}
	cout<<cnt;
	return 0;
}
