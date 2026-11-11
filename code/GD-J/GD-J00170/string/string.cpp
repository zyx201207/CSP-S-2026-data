#include <bits/stdc++.h>
using namespace std;
int leng[200010];
char cha[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> leng[i] >> cha[i]; 
	}
	int l=0,r=n-1;
	int jian;
	long long ans=0;
	while(l!=r){
		if(cha[l]==cha[r]){
			jian=min(leng[l],leng[r]);
			leng[l]=leng[l]-jian;
			leng[r]=leng[r]-jian;
		}
        if(cha[l]!=cha[r]){
			jian=min(leng[l],leng[r]);
			leng[l]=leng[l]-jian;
			leng[r]=leng[r]-jian;
			ans=ans+jian;
		}
		if(r-l==1&&leng[r]==0&&leng[l]==0)break; 
		if(leng[l]==0)++l;
		if(leng[r]==0)--r;
	}
	cout << ans;
	return 0;
} 
