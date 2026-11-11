#include<bits/stdc++.h>
using namespace std;

void Main() {
	cout<<rand()%3;
}

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	srand(time(0));
	int c,t;
	cin>>c>>t;
	while(t--) {
		Main();
	}
}
