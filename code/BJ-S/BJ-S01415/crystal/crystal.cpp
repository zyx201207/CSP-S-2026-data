#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sjzhi[500010];
long long sjcha[500010];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    cin>>n>>m;
    sjcha[0]=0;
    if(n==1&&m==0){
        cout<<1;
    }else{


    for(int i=1;i<=n;i++){
        cin>>sjzhi[i];
    }
    sort(sjzhi+1,sjzhi+n+1);
    
    /*for(int i=1;i<=n;i++){
        cout<<sjzhi[i]<<" ";
    }
    cout<<endl;*/
    
    for(int i=1;i<=n;i++){
        sjcha[i]=sjzhi[i]-sjzhi[i-1];
    }
	
	/*for(int i=1;i<=n;i++){
        cout<<sjcha[i]<<" ";
    }
    cout<<endl;*/
    
    int l=1,r=1,now=0,longst=0;
    while (r<=n&&l<=n) {
		if(l==r){
			r++;
			now+=sjcha[r];
			//cout<<"l"<<l<<endl;
			//cout<<"r"<<r<<endl;
			//cout<<"now"<<now<<endl;
		}
		else if(now<=m){
			longst=max(r-l+1,longst);
			//cout<<"longst"<<longst<<endl;
			r++;
			//cout<<"l"<<l<<endl;
			//cout<<"r"<<r<<endl;
			now+=sjcha[r]*(r-l);
			//cout<<"now"<<now<<endl;
		}
		else{
            l++;
			//cout<<"l"<<l<<endl;
			//cout<<"r"<<r<<endl;
            now-=sjzhi[r]-sjzhi[l-1];
			//cout<<"now"<<now<<endl;
        }
	}
    cout<<longst;


    }
    return 0;
}
