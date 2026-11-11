#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500007],d,e[500007],o[500007],i,j[500007],rt;
bool fg=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>b;
	for(int x=1;x<=a;x++){
		cin>>c[x];
	}
	sort(c+1,c+a+1);
	for(int x=1;x<=a;x++){
		d+=c[x];
		e[x]=d;
	}
	for(int x=1;x<=a-1;x++){
		o[x]=c[x+1]-c[x];
	}
	rt=o[1];
	for(int x=2;x<=a-1;x++){
		if(rt!=o[x]){
			fg=1;
			break;
		}
	}
	if(fg==0){
		__int128 cnt=0;
		bool so=0;
		for(int x=1;x<=a-1;x++){
			cnt+=x*rt;
			if(cnt>b){
				so=1;
				cout<<x;
				return 0;
			}
		}
		if(so==0){
			cout<<a;
			return 0;
		}
	}
	d=0;
	j[1]=1;
	for(int x=a;x>=1;x--){
		d=0;
		i=0;
		bool r=0;
		for(int y=x-1;y>=1;y--){
			i+=o[y];
			d+=i;
			if(d>b){
				r=1;
				d-=i;
				j[x]=x-y-1;
				break;
			}
		}
		if(r==0){
			j[x]=x;
		}
	}
	d=0;
	for(int x=1;x<=a;x++){
		d=max(d,j[x]);
	}
	cout<<d;
	return 0;
}
