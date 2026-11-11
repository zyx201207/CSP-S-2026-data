#include <bits/stdc++.h>
using namespace std;

const int N=3e5+10;
struct Str{
	int a;
	char b;
}v[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> v[i].a >> v[i].b;
	}
	long long res=0;
	for(int i=1,j=n;i<j;){
		int minn=min(v[i].a,v[j].a);
		if(v[i].b==v[j].b){
			v[i].a-=minn;
			v[j].a-=minn;
		}else{
			v[i].a-=minn;
			v[j].a-=minn;
			res+=minn;
		}
		if(v[i].a==0){
			i++;
		}
		if(v[j].a==0){
			j--;
		}
	}
	cout << res;
	return 0;
}
