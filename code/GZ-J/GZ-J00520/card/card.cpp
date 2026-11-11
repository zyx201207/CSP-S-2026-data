//准考证:GZ-J00520 学校:龙里县民族完全中学 姓名:李玮辰 
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> a(m+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	vector<int> z(m+1,0);
	for(int i=1;i<=n;i++){
		vector<bool> dist(m+1,0);
		vector<int> b;
		for(int j=i;j<=n;j++){
			if(dist[a[j]]){
				for(int c=j-1;a[c]!=a[j];c--){
					b.pop_back();
				}b.pop_back();
			}
			dist[a[j]]=1;
			b.push_back(a[j]);
		}
		for(int i=0;i<b.size();i++){
			z[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(z[i])printf("%d ",z[i]);
	}
	return 0;
}
