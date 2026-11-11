#include<iostream>

using namespace std;


long long sum = 0;
long long n,m;
long long p;

long long first[1000000];
long long second[1000000];

long long h = 0;
int ty[1000000];

int gh(){
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(ty[j]<ty[j+1]){
				int u = ty[j];
				ty[j] = ty[j+1];
				ty[j+1] = u;
			}
		}
	}
	/*for(int i = 0;i<n;i++){
		cout<<ty[i]<<" ";
	}
	cout<<endl;*/
	return ty[0];
}

int retry(long long g){//p计数，q顺序 ,g轮数 
	/*if(p>sum){//answer
		sum = p;
	}*/
	
	p = 0;
	//int ty[1000000];
	for(int i = 0;i<n;i++){
		ty[i] = 0;
	}
	for(int i = 0;i<n;i++){
		ty[second[i]]++;
	}
	p = gh();
	/*cout<<p<<"     "<<g<<"        ";
	for(int i = 0;i<n;i++){
		cout<<second[i]<<" ";
	}
	cout<<endl;//*/
	if(p>sum){
		sum = p;
	}
	if(g==m){//结束条件 
		return 0;
	}
	int w = g+1;
	for(int i = 0;i<n;i++){
		second[i]++;
		retry(w);
		second[i]--;
	}
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		long long j;
		cin>>j;
		first[i] = j;
		second[i] = j;
	}
	/*for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			if(second[j]>second[j+1]){
				int u = second[j];
				second[j] = second[j+1];
				second[j+1] = u;
			}
		}
	}*/
	retry(0);
	cout<<sum;
	return 0;
} 
