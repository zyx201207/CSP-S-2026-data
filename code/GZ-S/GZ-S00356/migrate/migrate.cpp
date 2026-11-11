//GZ-S00356，邱伟轩，贵阳市乌当第二中学
#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,t;
	vector<int>ans;
	cin>>c>>t;
	if(c==0)c++;
	while(c--){
		for(int i=0;i<t;i++){
			int n,d;
			int island[n];
			cin>>n>>d;
			for(int j=0;j<n;j++){
				cin>>island[j];
			}
			int s=0;
			for(int x=0;x<n;x++){
				for(int y=x;y<n;y++){
					if(x==y)continue;
					if(island[y]-island[x]>d){
						bool g=1;
						for(int a=x;a<y;a++){
							if(island[a+1]-island[a]>d){
								g=0;
								break;
							}
						}
						if(g&&y-x-1==2)s++;
					}
				}
			}
			ans.push_back(s);
		}
	}
	for(int i=0;i<t;i++)cout<<ans[i]<<'\n';
	return 0;
}
