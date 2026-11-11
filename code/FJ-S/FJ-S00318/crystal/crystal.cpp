#include<bits/stdc++.h>
using namespace std;
vector<long long>a;
inline long long rea(){
	long long x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}c=getchar();
	}while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n=rea(),m=rea();
	for(int i=0;i<n;i++)a.emplace_back(rea());
	stable_sort(a.begin(),a.end());
	long long l=0,r=0,now=0,ans=1,nowp=1;
	for(int i=0;i<n;i++){
		if(r==n-1){ans=max(ans,nowp);break;}
		while(r>l&&now+((a[r+1]-a[r])*(r-l+1))>m)nowp--,now-=a[r]-a[l++];
		if(l==r&&a[r+1]-a[r]>m)l++,r++;
		else{nowp++,now+=(a[r+1]-a[r])*(r-l+1),r++;}
		ans=max(ans,nowp);
	}cout<<ans;
	return 0;
}
