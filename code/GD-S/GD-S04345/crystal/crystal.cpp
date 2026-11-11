#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100000];
long long toal;
long long b[100000];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	
	}
	/*
	for(int i=1;i<=n;i++){
		if(m<b[i+1]-b[i])break;
		for(int j=i;j>=1;j--){
			if(m<b[i+1]-b[j])break;
			m-=b[i+1]-b[j];
			b[j]=b[i+1];
		}
	}
	*/

	
	for(int i=1;i<=n;i++){
		a[b[i]]++;
	}
	int cnt=1;//最高连续数 
	int maxx=-1;
	for(int i=b[1];i<=b[n];i++){
		if(a[i]==0)continue;
		if(a[i]>1&&a[i]>cnt){
			maxx=i;
			cnt=a[i];
		}
	}
	//cout<<max<<" "<<cnt<<endl;
	int ok=0;
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		if(b[i]==maxx&&ok==0){
			x=i;
			ok=1;
		}
		if(b[i]==maxx&&ok!=0){
			y=i;
		}
	}
	//cout<<x<<" "<<y<<" "<<max<<endl;
	
//-----------------------------------------好 

//---------------------------
//cout<<x<<" "<<y<<" "<<maxx<<endl;
	if(x==0&&y==0){
		int sp=0;
		if(b[1]>0){
			sp=b[1];	
		}
		else{
			sp=0-b[1];
		}
		for(int i=2;i<=n/2;i++){
			int p=b[i]-b[i-1];
			if(p<=sp&&m>=p){
				sp=p;
				x=i-1;
				y=i;
				
			}
		}
		m-=b[y]-b[x];
		b[x]=b[y];
		maxx=b[y];
		//cout<<sp<<endl;
	}
//	cout<<x<<" "<<y<<" "<<maxx<<endl;

		int cz=0;
		for(int i=x;i<=y;i++){
			cz+=b[y+1]-b[i];
		}
		//cout<<cz; 
		//cout<<x<<" "<<y<<" "<<maxx<<endl;
		while(m>=maxx-b[x-1]||m>=cz){
			
			//cout<<1;
			if(y==n){
				for(int i=x-1;i>=1;i--){
					if(b[y]-b[i]<=m){
						m-=b[y]-b[i];
						b[i]=b[y];
						x=i;
						cnt++;
					}
					else{
						break;
					}
				}
				break;
			}
			
			cz=0;
		
			for(int i=x;i<=y;i++){
					cz+=b[y+1]-b[i];
				}
			
			
			//cout<<m<<endl;
			if(cz>maxx-b[x-1]){
					
					if(x-1<1){
						break;
					}
					m-=maxx-b[x-1];
					cnt++; 
					b[x-1]=maxx;
				//	cout<<m<<endl;
					x=x-1;
				
				
			
			}
			
			if(cz<=maxx-b[x-1]){
					if(y+1>n){
						break;
					}
					//cout<<1<<endl;
					m-=cz;
					maxx=b[y+1];
					cnt++;
					
					for(int i=x;i<=y;i++){
						b[i]=maxx;
					}
					y=y+1;
				
			}
			
			
		}
		//cout<<x<<" "<<y<<" "<<maxx<<endl;
		/*
		for(int i=1;i<=n;i++){
			a[b[i]]++;
		}
		int e=0;
		for(int i=1;i<=n;i++){
			e=max(e,a[i]);
		}
		*/
		cout<<y-x+1;
	
	return 0;
} 
/*
11 45
-100 1 2 3 4 5 6 7 8 9 10
10

5 10
1 2 3 4 5
5

5 5
1 2 4 8 9
3

5 8
-3 -1 2 2 7
4

&&
5 10
1 2 2 2 10
4

5 3
-1 9 9 9 10
4
*/
