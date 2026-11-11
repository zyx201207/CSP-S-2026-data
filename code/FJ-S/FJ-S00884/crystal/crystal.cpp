#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

namespace lyh{
	
	#define int long long
	
	const int N = 666666;
	int n,m,a[N],s;
	
	void inlyh(){
		cin>>n>>m;
		for(int i = 1;i <= n;i++) cin>>a[i];
		return;
	}
	
	void solyh(){
		sort(a + 1,a + n + 1);
		int i,j,sum = 0;
		j = 1;
		for(i = 1;i <= n;i++){
			sum += (a[i] - a[i - 1]) * (i - j);
			while(sum > m){
				sum -= a[i] - a[j];
				j++;
			}
			s = max(s,i - j + 1);
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
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		return;
	}
	
	#undef int
	
}

int main(){
	lyh::fre();
	lyh::lyh();
	return 0;
}
