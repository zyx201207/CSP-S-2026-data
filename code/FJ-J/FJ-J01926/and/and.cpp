#include <bits/stdc++.h>
using namespace std;
struct node{
	long long v;
	int cnt1;
}a[200005];
int f(long long x){
	string s="";
	while(x!=0){
		s+=x%2+'0';
		x/=2;
    }
    int l=s.size();
    int cnt1=0;
    for(int i=0;i<l;i++){
    	if(s[i]=='1'){
    		cnt1++;
        }
    }
    return cnt1;
}
bool cmp(node x,node y){
	if(x.cnt1==y.cnt1){
		return x.v>y.v;
    }
	return x.cnt1>y.cnt1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].v;
		a[i].cnt1=f(a[i].v);
    }
    sort(a+1,a+1+n,cmp);
    long long vp=a[1].v;
    for(int i=2;i<=m;i++){
    	vp=vp&a[i].v;
    }
    cout<<vp;
	return 0;
}
