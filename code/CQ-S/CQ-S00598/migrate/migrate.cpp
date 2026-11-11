#include <bits/stdc++.h>
using namespace std;
#define gc getchar
long long sid,T,n,d,m,R[2000005],a[2000005],now,x,y,zym,aa,l,r,s,bb;
queue<long long> shanshan;
deque<pair<long long,long long> > hsfzy;
vector<long long> t;
inline long long rd(){
	long long r_x=0,r_c=0;
	r_c=gc();
	while(!isdigit(r_c)){
		r_c=gc();
	}
	while(isdigit(r_c)){
		r_x=(r_x<<3)+(r_x<<1)+(r_c^48);
		r_c=gc();
	}
	return r_x;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	*cin.tie(nullptr)<<fixed<<setprecision(20);
	cout.tie(nullptr)->ios_base::sync_with_stdio(false);
	sid=rd();
	T=rd();
	while(T--){
		n=rd();
		d=rd();
		for(int i=1;i<=n;++i){
			a[i]=rd();
		}
		l=r=0;
		for(int i=1;i<=n;++i){
			if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
				if(l==0){
					l=r=i;
				}
				else{
					++r;
				}
			}
		}
		if(l!=0){
			for(int i=1;i<=n;++i){ 
		 		while(!shanshan.empty()&a[i]-a[shanshan.front()]>d){
		 			R[shanshan.front()]=i-1;
		 			shanshan.pop();
				}
				shanshan.push(i);
			}
			while(!shanshan.empty()){
				R[shanshan.front()]=n;
				shanshan.pop();
			}
			if(R[1]==n){
				cout<<0<<endl;
				continue;
			}
			while(!hsfzy.empty()){
				hsfzy.pop_front();
			}
			for(int j=l-1;j>=1;--j){
				if(j==l-1){
					for(int k=R[j];k>=j+1;--k){
						hsfzy.push_back(make_pair(k,min(R[k],n)));	
					}
				}
				else{
					while(!hsfzy.empty()&&hsfzy.front().first>R[j]){
						hsfzy.pop_front();
					}
				}
				if(hsfzy.size()>=2){
					if(hsfzy.size()==2){
						zym+=hsfzy.back().second-R[j];
					}
					else{
						aa=hsfzy.size()-2;
						zym+=hsfzy[aa].second-hsfzy[aa-1].second;
					}
				}
			}			
		}
		else{
			zym=0;
			for(int i=1;i<=n;++i){
				t.clear();
				t.push_back(i);
				t.push_back(i+1);
				s=0;
				now=0;
				for(int j=i+2;j<=n;++j){
					if(s==2){
						break;
					}
					aa=t.back();
					if(a[j]-a[aa]>d){
						break;
					}
					t.pop_back();
					if(a[j]-a[t.back()]<=d){
						t.push_back(j);
					}
					else{
						t.push_back(aa);
						t.push_back(j);
					}
					while(now<j-1){
						++now;
						bb=lower_bound(t.begin(),t.end(),now)-t.begin();
						if(t[bb]==now){
							continue;
						}
						if(t.size()>=3){
							if(a[t[bb]]-a[now]<=d&&a[now]-a[t[bb-2]]<=d){
								++s;
							}
						}
					}
					if(s==1){
						++zym;
					}
				}
			}
		}
		cout<<zym<<endl;
	}
	return 0;
}

