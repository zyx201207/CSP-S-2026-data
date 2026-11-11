#include<iostream>
using namespace std;

namespace lyh{
	
	const int N = 333333,M = 30;
	int n,m,a[N],s;
	
	void inlyh(){
		cin>>n>>m;
		for(int i = 1;i <= n;i++) cin>>a[i];
		return;
	}
	
	void solyh(){
		int x,y;
		for(int i = M;~i;i--){
			x = 0;
			y = s | (1<<i);
			for(int j = 1;j <= n;j++){
				if((a[j] & y) == y) x++;
			}
			if(x >= m) s = y;
		}
		return;
	}
	
	void outlyh(){
		cout<<s;
		return;
	}
	
	void lyh(){
		inlyh();
		solyh();
		outlyh();
		return;
	}
	
	void fre(){
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
		return;
	}
	
}

int main(){
	lyh::fre();
	lyh::lyh();
	return 0;
}
