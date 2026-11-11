#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq;
int w[200002];
struct xx{
	int k;
	int a[5002];
	int t[5002];
};
int r,l;
long long s=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	xx q[501];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>q[i].k;
		for(int j=1;j<=q[i].k;j++){
			cin>>q[i].a[j]>>q[i].t[j];
		}
	}
	for(int u=0;u<qq;u++){
		cin>>l>>r;
		s=w[l]+w[r];
		int o=0,p=0;
		int ll=0,rr=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=q[i].k;j++){
				if(q[i].a[j]==l&&p==0){
					s+=q[i].t[j];
					p=1;ll=i;
				}
				if(q[i].a[j]==r&&o==0){
					s+=q[i].t[j];
					o=1;rr=i;
				}
			}
		}
		if(ll==rr){
			cout<<s<<endl;
		}else{
			int h=0;
			for(int i=1;i<=q[ll].k;i++){
				for(int j=1;j<=q[rr].k;j++){
					if(q[ll].a[i]==q[rr].a[j]){
						h=1;
						s+=q[ll].t[i];
						s+=q[rr].t[j];
						break;
					}
				}
				if(h==1){
					cout<<s<<endl;
					break;
				}
			}
			if(h==0){
				for(int kk=1;kk<=n;kk++){
				for(int i=1;i<=q[ll].k;i++){
				for(int j=1;j<=q[kk].k;j++){
					if(q[ll].a[i]==q[kk].a[j]){
						s+=q[ll].t[i];
						s+=q[kk].t[j];
						ll==kk;
						if(kk==rr){
							cout<<s<<endl;
						}
						break;
					}
				}
			}
				}
			}
		}
	}
	return 0;
} 
