#include<iostream>
#include<string>

using namespace std;
const int maxn=2e5+5;
struct node{
	long long cnt;
	char ch;
	void input(){
		cin>>cnt>>ch;
	}
	void output(){
		cout<<ch<<" "<<cnt<<endl;
	}
};
node a[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i].input();
	//	a[i].output();
	}cout<<" "<<n<<endl;
	cout<<n;
	for(int i=1,j=n;i<=j;){
		if(a[i].cnt>a[j].cnt){
			if(a[i].ch!=a[j].ch)ans+=(a[j].cnt);
			a[i].cnt-=a[j].cnt;
			j--;
		}else if(a[i].cnt==a[j].cnt){
			if(a[i].ch!=a[j].ch)ans+=(a[i].cnt);
			i++,j--;
		}else{
			if(a[i].ch!=a[j].ch)ans+=(a[i].cnt);
			a[j].cnt-=a[i].cnt;
			i++;
		}
		//Sleep(100);
		cout<<a[i].cnt<<" "<<a[j].cnt<<endl;
	}
	cout<<ans;
} 
