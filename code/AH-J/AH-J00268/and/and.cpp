#include<bits/stdc++.h>
using namespace std;

const int N=200005;

int n,m;
bool a[N][35],used[N],k[35];
int sum[35];

void read(int num){
	long long x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	int cnt=1;
	while(x>0){
		a[num][cnt]=x%2;
		if(x%2) sum[cnt]++;
		x/=2;
		cnt++;		
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		read(i);	
	}	
	int wei=32;
	while(sum[wei]<m&&wei>0) wei--;
	if(wei==0) {
		puts("0");
		return 0;
	}
	k[wei]++;
	queue<int> q;
	for(int i=1;i<=n;i++)	if(a[i][wei]) q.push(i);
	for(int i=wei-1;i>=1;i--){
		queue<int >qy,qw;
		int o=0;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			if(a[now][i]==0){
				qw.push(now);
			}
			else{
				qy.push(now);
				o++;
			}
		}
		if(o<m){
			while(!qy.empty()){
				int now=qy.front();
				qy.pop();
				q.push(now);
			}
			while(!qw.empty()){
				int now=qw.front();
				qw.pop();
				q.push(now);
			}
		}
		else{
			k[i]++;
			while(!qy.empty()){
				int now=qy.front();
				qy.pop();
				q.push(now);
			}
		}
	}
	long long ans=0;
	for(int i=wei;i>=1;i--){
		ans=ans*2+k[i];
	}
	cout<<ans<<endl;
	return 0;
}
