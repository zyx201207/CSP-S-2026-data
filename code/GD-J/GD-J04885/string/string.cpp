#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct node{
	long long a;
	char c;
};
vector<node> v(200001);
bool cmp(node x,node y){
	return x.c>y.c;
}
bool cmp2(node x,node y){
	return x.a>y.a;
}
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	int n,f=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i].a>>v[i].c; 
		sum+=v[i].a;
	}
	for(int i=1;i<n;i++){
		if(v[i].c!=v[i-1].c){
			f=0;
		} 
	}
	if(f){
		cout<<"0";
		return 0;
	}
	if(sum%2==0){
		long long x=v[0].a;
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<=n;i++){
			if(v[i].c==v[i+1].c){
				x+=v[i].a;
			}else{
				break;
			}
		}
		cout<<sum-x;
		return 0;
	}else{
		long long x=0;
		sort(v.begin(),v.end(),cmp2);
		if(v[n-1].a%2==0){
			x++;
			v[n-1].a-=1;
		}
		for(int i=0;i<=n-1;i++){
			int j=abs(n-i-1);
			if(v[i].c!=v[j].c){
				x+=v[i].a;
				v[j].c=v[i].c;
			}
		}
		cout<<x;
		return 0;
	}
	return 0;
} 
