////crystal.cpp 
#include<bits/stdc++.h>
using namespace std;
const int MAXN=500000;
int n,m,x,y;
long long a[MAXN];
bool Used[MAXN];
long long lowNum=0,UCnum=1,ConNum=0;
long long temp;
int pi,pj;
void pop(){
	for(pi=n+1;pi>=1;pi--){
		bool flag=true;
		for(pj=0;pj<pi-2;pj++){
			if(a[pj]>a[pj+1]) swap(a[pj],a[pj+1]);
			flag = false;
		}
		if(flag) break;
	}
	
}

void dfs(int step)
{
	if(UCnum<lowNum) return;
	if(ConNum>m) return;
	
	for(int mm=0;mm<n;mm++)
	{
		for(y=2;y<n;y++)
		{
			if(temp < m){
				UCnum++;
				ConNum++;
				lowNum++;
				temp += (a[n-y]-a[n-y-1]);
			}else if(temp>m){
				n--;
				continue;
			}
		}
	}
	dfs(step-1);
	cout<<UCnum;
	
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	pop();
	temp = a[n-1] - a[n-2];	
	dfs(n);
	return 0;
	fclose(stdin);
	fclose(stdout);
}	
