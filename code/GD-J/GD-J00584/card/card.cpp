#include<bits/stdc++.h>
using namespace std;
int a[200005], b[200005];
map<int,int> ans;
int ef(int x,int r){
    int i;
    for(i=0;i<r;i++){
        if(b[i]==x){
            return i;
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, i, j, m, t, efj;
	cin>>n>>m;
	for(i=0;i<n;i++){
        cin>>a[i];
	}
	ans[a[n-1]]++;
	for(i=0;i<n-1;i++){
        t=0;
        for(j=i;j<n;j++){
            efj=ef(a[j],t);
            if(efj==-1){
                b[t++]=a[j];
            }else{
                t=efj+1;
            }
        }
        for(j=0;j<t;j++){
            ans[b[j]]++;
        }
	}
	for(auto it:ans){
        cout<<it.second<<' ';
    }
	return 0;
}
