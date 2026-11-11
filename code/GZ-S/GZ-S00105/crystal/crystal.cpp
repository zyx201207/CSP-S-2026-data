//GZ-S00105,刘啸行,贵阳市新世界学校
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],ms[500005],s[500005];
int ans[500005];ll n,m;
int check(int dn,int g,int gi){
	int di = dn*g-s[dn];
	if(ms[gi]-di>m)return 0;
	else if(ms[gi]-di==m)return 2;
	else return 1;
}
int find(int g,int gi){
	int l = 1,r = gi,mid=-1,anss=-1;
	while(l<=r){
		mid = (l+r)/2;
		int ch = check(mid,g,gi);
		if(ch==1){
			r=mid-1;
			anss = mid;
		}else if(ch==2){
			return mid;
		}else if(ch==0){
			l=mid+1;
		}
	}if(anss==-1){
		return ans[gi-1];
	}
	return anss;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	
	int ind = 0;
	ms[1]=0;
	a[0]=-1e13;
	ans[0]=0;
	int div = -1;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}sort(a+1,a+1+n);

	for(int i = 1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		if(a[i]==a[i-1])ans[ind]++;
		else{
			ind++;
			ans[ind]=1+ans[ind-1];
			if(ind!=1){
				div=a[i]-a[i-1];
				ms[ind]=ms[ind-1]+ans[ind-1]*div;
			}
		}
	}
	int len = unique(a+1,a+1+n)-a-1;
	
	int result = -1;int ri=0;
	for(int i = len;i>=1;i--){
		if(ms[i]<=m){
			if(ans[i]>result)result = ans[i];ri=i;
			break;
		}
		int res = ans[i]-find(a[i],i);
		if(res>result){
			result=res;ri=i;
		}
	}
	cout << result;
    return 0;
}

