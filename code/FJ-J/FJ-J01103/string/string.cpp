#include<iostream>
using namespace std;

namespace lyh{
	
	#define int long long
	
	const int N = 333333;
	int n,a[N],b[N],s;
	
	void inlyh(){
		char c;
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i]>>c;
			a[i] += a[i - 1];
			b[i] = c - 'a';
		}
		a[n + 1] = a[n];
		return;
	}
	
	void solyh(){
		int i,j;
		int x,y;
		i = 1;j = n + 1;
		x = 0;y = -1;
		while(i < j){
			s += min(x,a[i] - a[i - 1]) * (b[i] != y);
			while(a[n] - a[j - 1] < a[i]){
				j--;
				s += min(a[j] - a[j - 1],a[i] - (a[n] - a[j])) * (b[i] != b[j]);
			}
			x = a[n] - a[j - 1] - a[i];
			y = b[j];
			i++;
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
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
		return;
	}
	
	#undef int
	
}

int main(){
	lyh::fre();
	lyh::lyh();
	return 0;
}
