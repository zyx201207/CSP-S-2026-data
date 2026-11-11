#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500200],cnt=1,maxs,maxw,maxn=0;
long long m,dm,fm=0;
long long js(int s,int w){
	int e=0;
	for(int i=s;i<=w;i++){
		e+=(a[w]-a[i]);
	}
	return e;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long s,w,jz;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dm=m;s=1;
	/*for(int i=1;i<=n-maxn;i++){
		s=i;
		w=i;
		fm=0;
		while(w<=n&&s>=1){
			if((js(s,w+1)<=js(s-1,w))&&(min(js(s,w+1),js(s-1,w))<=m)&&(w<n)){
				if(w<n){w++;cnt++;}
			}else{
				if(s>1){s--;cnt++;}
			}
			if(((a[s+1]-a[s])>(a[w+1]-a[w]))&&(js(s+1,w+1)<m)){
				s++;w++;
			}else if(((a[s]-a[s-1])>(a[w]-a[w-1]))&&(js(s-1,w-1)<m)){
				s--;w--;
			}else if(maxn<cnt){
				maxn=cnt;
				maxs=s;
				maxw=w;
				break;
			}
		}
	}*/
	for(int i=1;i<=n;i++){
		s=i;w=i;cnt=1;m=dm;
		while(m){
			jz=a[i];
			if(w<=n&&m>0){
			    if((s>1)&&((m-(jz-a[s-1]))>=0)){
					s--;cnt++;m=m-(jz-a[s]);
				}else{
					break;
				}
			}else{
				break;
			}
		}
		//cout<<s<<' '<<w<<' '<<dm-m<<endl;
		if(maxn<cnt){
			maxn=cnt;
			maxs=s;
			maxw=w;
		}
	}
	cout<<maxn;
	return 0;
}
