#include <bits/stdc++.h>



using namespace std;
int n;
int m;
int nlz[100000];
int pxh[100000];
int sl1 = 0;
int sl = 0;
vector<int> nl;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>nlz[i+1];
		sl+=1;
	}
	//under code is paixu
	for(int i = 0;i<1;i++){
		for(int r = 0;r < n;r++){
			//cout<<r<<endl;
			if(sl % 2 == 1){
				if(nlz[r+1] > nlz[r+2]){
				if(r == sl){
				//cout<<nlz[r+2]<<endl;
				//cout<<nlz[r]<<endl;
				int f = nlz[r];
				int s = nlz[r+1];
				pxh[r+1] = s;
				pxh[r] = f;
				break;
				}
				//cout<<nlz[r+1]<<endl;
				//cout<<nlz[r+2]<<endl;
				int f = nlz[r+1];
				int s = nlz[r+2];
				pxh[r+1] = s;
				pxh[r+2] = f;
			    }
			}else{
				if(nlz[r+1] > nlz[r+2]){
				//cout<<nlz[r+1]<<endl;
				//cout<<nlz[r+2]<<endl;
				int f = nlz[r+1];
				int s = nlz[r+2];
				pxh[r+1] = s;
				pxh[r+2] = f;
			    }
			}
			
		}
	}
	for(int i = 0;i<n;i++){
		//cout<<pxh[i+1];
	}
	//cout<<endl;
	cout<<pxh[1] + pxh[2]<<endl;
	
	return 0;
}
