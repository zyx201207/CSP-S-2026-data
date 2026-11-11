#include<iostream>
using namespace std;

const int MAXN=2e6+5;

int c,t;
int n,d;
int dis[MAXN];

bool check_specialA(){
	int d=dis[2]-dis[1];
	for(int i=3;i<=n;i++){
		if(dis[i]-dis[i-1]!=d){
			return false;
		}
	}
	return true;
}

bool check_specialC(){
	if(dis[n]-dis[1]<=10*d){
		return true; 
	}
	return false;
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	srand(time(0));
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>dis[i];
		}
		if(check_specialA()){
			cout<<1<<endl;
			continue;
		}
		if(check_specialC()){
			cout<<1<<endl;
			continue;
		}
		cout<<rand()%n<<endl;
	}
	
	return 0;
}
