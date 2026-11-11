#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int c,n,m,d,q;
int w;
struct kk{
	int k;
	long long a[50001];
};
int x,y;

void code(int m1,int n1,int q1){
	int w[m1];
	kk kkk[n1];
	int stime=0;
	for(int i=0;i<m1;i++){cin>>w[i];}
	for(int ii=0;ii<n1;ii++){cin>>kkk[ii].k; 
							for(int iii=0;iii<kkk[ii].k;iii++){cin>>kkk[ii].a[iii];}}
	for(int iv=0;iv<q1;iv++){
		cin>>x>>y;
		stime = w[x-1]+w[y-1];
		for(int vi=0;vi<n1;vi++){
			int k_te=kkk[vi].k;
			int start=0,s_h,end=0,e_h=0;
			for(int ik=0;ik<k_te;ik++){
				if(kkk[vi].a[ik]==x){
					start = vi+1; s_h=ik;
				}
				else if(kkk[vi].a[ik]==y){
					end = vi+1; e_h=ik;
				}
			}
		}
		if(start==end){stime+=(kkk[start].a[s_h]+kkk[start].a[e_h]);}
		else{stime+=}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	//ios:sync_with_stdio(false);
	//cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	code(m,n,q);
	return 0;
}
