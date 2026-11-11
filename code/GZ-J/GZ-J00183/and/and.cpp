//GZ-J00183，乔浩宇，安顺市实验学校
#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long cnt[m+5];
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
	}
	long long maxn=0;
	for(int j=1;j<=n;j++){
		if(cnt[j] and cnt[j+1]>maxn){
			maxn=cnt[j] and cnt[j+1];
		}
	}
	cout<<maxn;
	return 0;
}
