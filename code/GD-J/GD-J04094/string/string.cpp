#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
struct stu{
	long long a;
	char x;
};
deque<stu>v;
int n,vl;
long long cnt[1006];
void add(long long a){
	long long d=a;
	int cl=1; 
	while(d){
		cnt[cl]+=d;
		d=0;
		d=cnt[cl]/10;
		cnt[cl]%=10;
		cl++;
	} 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int b;char c;
		cin>>b>>c;
		v.push_back(stu{b,c});
		vl++;
	}
	vl-=1;
	
	for(int j=0;j<vl;){
		if(v[j].x==v[vl].x){
			if(v[j].a>v[vl].a){
				v[j].a-=v[vl].a;
				vl--;
			}else if(v[j].a==v[vl].a){
				vl--;
				j++;
			}else{
				v[vl].a-=v[j].a;
				j++;
			}
		}else{
			if(v[j].a>v[vl].a){
				add(v[vl].a);
				v[j].a-=v[vl].a;
				vl--;
			}else if(v[j].a==v[vl].a){
				add(v[vl].a);
				vl--;
				j++;
			}else{
				add(v[j].a);
				v[vl].a-=v[j].a;
				j++;
			}
		}
	}
	int cc=20;
	while(cnt[cc]==0&&cc>=1){
		cc--;
	}
	for(int i=cc;i>=1;i--){
		cout<<cnt[i];
	}
	return 0;
	
}

