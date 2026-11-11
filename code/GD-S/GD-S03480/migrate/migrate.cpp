#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long x[2000005];
long long d;
int to[2000005];
vector<vector<int> > vs;
void road(int dest,vector<int> path){
//	printf("res dest is %d\n",dest);
	for (int i:path){
//		printf("now i %d\n",i);
	}
	if (path[path.size()-1]==dest)vs.push_back(path);
	
	else{
//		printf("dd");
		int bei=path[path.size()-1];
		path.push_back(0);
//		printf("from i %d\n",path[int(path.size())-1]+1);
//		printf("to i %d\n",to[path[int(path.size())-1]]);
		for (int i=bei+1;i<=dest&&i<=to[bei];i++){
//			printf("kill i %d\n",i);
			path.pop_back();
			path.push_back(i);
			road(dest,path);
		}
	}
}
bool cmp(vector<int> a,vector<int> b){
	return a.size()<b.size();
}
bool judge(int a,int b){
	if (x[b]-x[a]<=d)return 0;
	if (b<=a+2)return 0;
	vs.clear();
	vector<int> tem;
	tem.push_back(a);
	road(b,tem);
	sort(vs.begin(),vs.end(),cmp);
//	for (auto i:vs){
//		cout<<endl;
//		for (int j:i)cout<<j<<' ';
//		cout<<endl;
//	}
	if (vs.empty())return 0;
	
	else {
		int fir=int(vs[0].size());
		int siz=0;
		for (int i=0;i<vs.size();i++){ 
			if (int(vs[i].size())==fir){
				siz++; 
			}
			else break;
		}
//		printf("js a %d b %d siz %d\n",a,b,siz);
		if (siz==2)return 1;
		else return 0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	
	for (int timer=1;timer<=t;timer++){
		scanf("%d%lld",&n,&d);
		for (int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		long long res=0;
		
		for (int i=1;i<=n;i++){
			to[i]=i;
			for (int j=i+1;j<=n;j++){
				if (x[j]-x[i]<=d)to[i]=j;
				else break;
			}
//			printf("i%d to is %d\n",i,to[i]);
		}
		
		for (int i=1;i<=n-1;i++){
			for (int j=i+1;j<=n;j++){
				if (judge(i,j))res++;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
	
	
}
