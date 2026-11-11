#include<bits/stdc++.h>
using namespace std;
struct pa{
	int anss;//min_answer
	int app;//appear
};
pa cnt(vector<int>m,vector<int>t,int f,int e,int p,int step){
	if(f==e){
		pa r;
		r.anss=step;
		r.app=1;//cout<<1;
		return r;
		
	}
	else if(f>e){
		pa ks;
		ks.anss=100866767;
		return ks;
	}
	pa ans;
	ans.anss=100866767;
	for(int i=1;i<=p;i++){
		pa ans1=cnt(m,t,f,e-i,p,step+1);
		if(ans1.anss<ans.anss){
			ans=ans1;
		}
		else if(ans1.anss==ans.anss){
			ans.app+=ans1.app;
		}
	}
	return ans;

}
//struct u{
//	int now;
//	int to;
//	int step;
//	
//};
//int cnt(vector<int>m,int f,int e,int p){
//	queue<u>q;
//	u fr;
//	fr.now=e,fr.step=0,fr.to=f;
//	q.push(fr);
//	while(!q.empty()){
//		fr=q.front();
//		q.pop();
//		if(fr.now==fr.to){
//			int s=fr.step;
//			int ans=1;
//			while(!q.empty()){
//				u ff=q.front();
//				q.pop();
//				//if(ff.step==fr.step&&ff.now==ff.to) ans++;
//				if(ff.step==fr.step) ans++;cout<<67;
//			}
//			return ans;
//		}
//		if(fr.now<fr.to) continue;
//		int i=1;
//		while(m[fr.now]-m[fr.now-i]<=p){
//			i++;
//			u pu;
//			pu.now=fr.now-1;
//			pu.to=e;
//			pu.step=fr.step+1;
//			q.push(pu);//
//		}
//	}
//	return 100866767;
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		vector<int>a(2000004,0);
		int ans=0;
		vector<int>tmp(2000004,0);
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			a[j]=x;
		}
		for(int i=0;i<n/2+1;i++){
			for(int j=n-1;j>n/2;j--){
				if(cnt(a,tmp,a[i],a[j],d,0).app==2){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
} 
