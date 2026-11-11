#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct charr{
	int many;
	char c;
};
charr a[N];
vector<pair<unsigned long long,char>> v;
vector<pair<unsigned long long,char>> f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].many>>a[i].c;
	}
	int sum=0;
	unsigned long long num=0;
	for(int i=1;i<=n;i++){
		if(a[i].many%2==1){
			sum++;
		}
		num+=a[i].many;
	}
	unsigned long long ans=0;
	if(sum%2==1){
		unsigned long long id=num/2+1;
		int i;
		unsigned long long y=0;
		for(i=1;;i++){
			if(y+a[i].many<id){
				y+=a[i].many;
				v.push_back({a[i].many,a[i].c});
			}else{
				if(id-1-y!=0){
					v.push_back({id-1-y,a[i].c});
				}
				
				break;
			}
		}
		int x=i;
		for(int d=1;i<=n;i++,d++){
			if(d==1){
				if(a[i].many-(id-1-y)-1!=0){
					f.push_back({a[i].many-(id-1-y)-1,a[i].c});
				}
				
			}else{
				f.push_back({a[i].many,a[i].c});
			}
		}
		for(int V=v.size()-1,F=0;;){
			if(v[V].second==f[F].second){
				if(v[V].first==f[F].first){
					v[V].first=0;
					f[F].first=0;
					F++;
					V--;
					break;
				}else if(v[V].first>f[F].first){
					
					v[V].first-=f[F].first;
					f[F].first=0;
					F++;
					
				}else{				
					f[F].first-=v[V].first;
					v[V].first=0;
					V--;
				}
			}else{
				if(v[V].first==f[F].first){
					ans+=v[V].first;
					v[V].first=0;
					f[F].first=0;
//					break;
				}else if(v[V].first>f[F].first){
					ans+=f[F].first;
					v[V].first-=f[F].first;
					f[F].first=0;
					F++;
					
				}else{
					ans+=v[V].first;
					f[F].first-=v[V].first;
					v[V].first=0;
					V--;
				}
			}
			if(V==-1&&F==f.size()){
				break;
			}
		}
	}else{
		unsigned long long l=num/2;
		unsigned long long r=l+1;
		int i;
		unsigned long long y=0;
		char c_l,c_r;
		for(i=1;;i++){
			if(y+a[i].many<l){
				y+=a[i].many;
				v.push_back({a[i].many,a[i].c});
			}else{
				v.push_back({l-1-y,a[i].c});
				c_l=a[i].c;
				break;
			}
		}
		unsigned long long x;
		if(l-1-y+2>a[i].many){
			i++;
			x=l-1-y+2-a[i-1].many;
			c_r=a[i].c;
		}else{
			c_r=a[i].c;
		}
		for(int d=1;i<=n;i++,d++){
			if(d==1){
				f.push_back({a[i].many-x,a[i].c});
			}else{
				f.push_back({a[i].many,a[i].c});
			}
		}
		for(int V=v.size()-1,F=0;;){
			if(v[V].second==f[F].second){
				if(v[V].first>f[F].first){
					v[V].first-=f[F].first;
					f[F].first=0;
					F++;
				}else if(v[V].first==f[F].first){
					v[V].first=0;
					f[F].first=0;
					F++;
					V--;
				}else{				
					f[F].first-=v[V].first;
					v[V].first=0;
					V--;
				}
			}else{
				if(v[V].first>f[F].first){
					ans+=f[F].first;
					v[V].first-=f[F].first;
					f[F].first=0;
					F++;
				}else if(v[V].first==f[F].first){
					ans+=v[V].first;
					v[V].first=0;
					f[F].first=0;
					V--;
					F++;
				}else{
					ans+=v[V].first;
					f[F].first-=v[V].first;
					v[V].first=0;
					V--;
				}
			}
			if(V==-1&&F==f.size()){
				break;
			}
		}
		if(c_l!=c_r){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
