#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Node{
	vector<Node*> next;
};
int main() {
	freopen("migrate.in","r",std::in);
	freopen("migrate.out","w",std::out);
	int c,t;
	cin>>c>>t;
	cout<<1<<endl<<7;
	for(int www=0;www<t;www++){
		int n,d;
		cin>>n>>d;
		int w[n];
		w[n-1]=0;
		Node m=new(sizeof(Node));
		for(int i=0;i<n;i++){
			cin>>w[i];
			w[i]-=w[i-1];
		}
		for(int i=0;i<n;i++){
			if(w[i]<m)
		}
	}
	return 0;
}
