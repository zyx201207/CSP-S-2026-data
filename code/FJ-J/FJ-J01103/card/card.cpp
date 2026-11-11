#include<iostream>
using namespace std;

namespace lyh{
	
	const int N = 666666;
	int n,m,a[N],tp[N],v[N],s[N]; 
	
	void inlyh(){
		cin>>n>>m;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			tp[a[i]] = i;
			v[i] = 1;
		}
		return;
	}
	
	void solyh(){
		for(int i = 1;i <= n;i++){
			if(i == tp[a[i]]){
				s[a[i]] += v[i];
				v[i + 1] += v[i];
			}
			else v[tp[a[i]]] += v[i];
		}
		return;
	}
	
	void outlyh(){
		for(int i = 1;i <= m;i++) cout<<s[i]<<' ';
		return;
	}
	
	void lyh(){
		inlyh();
		solyh();
		outlyh();
		return;
	}
	
	void fre(){
		freopen("card.in","r",stdin);
		freopen("card.out","w",stdout);
		return;
	}
	
}

int main(){
	lyh::fre();
	lyh::lyh();
	return 0;
}
