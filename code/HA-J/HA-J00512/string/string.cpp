#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],k,p,r,mid,sum;
vector<long long>v;
vector<char>c;
char q;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r>>q;
		v.push_back(r);
		c.push_back(q);
		k+=r;
	}
	if(k%2==0){
		mid=k/2;
	}else{
		mid=k/2+1;
	}
	int m=mid;
	for(int i=0;i<n;i++){
		bool f=0;
		mid-=v[i];
		if(mid==0){
			p=i;
			break;
		}
		else if(mid<0){
			p=i;
			for(int j=1;j<=v[i];j++){
				if(mid+j==0){
					v[i]=j;
					v.insert(v.begin()+i,v[i]-j+1);
					c.insert(c.begin()+i,c[i]);
					f=1;
					break;
				}
			}
		}
		if(f) break;
	}
	for(int i=0;i<=p;i++){
		if(v[v.size()-i-1]!=v[i]||c[c.size()-i-1]!=c[i]){
			sum+=v[i];
		}
	}
	cout<<sum;
	return 0;
}
