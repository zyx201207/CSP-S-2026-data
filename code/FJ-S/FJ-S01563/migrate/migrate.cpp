#include<bits/stdc++.h>
using namespace std;
int n,d,a[10005],minn,sum;
void find(int r,int note,int old_note,int num){
	if(note>=r){
		if(minn>num){
			minn=num;
			sum=0;
			return;
		}else{
			sum++;
			return;
		}
	}
	if(a[note+1]-a[old_note]<=d){
		find(r,note+1,note,num+1);
		find(r,note+1,old_note,num);
	}
	else
		find(r,note+1,note,num+1);
}
int main(){
	/*freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);*/
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c;
	if(c==0){
		cin>>t;
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					minn=0;sum=0;
					find(j,i+1,i,1);
					if(sum==2)ans++;
				}
			}cout<<ans<<endl;
		}
	}
	return 0;
}
