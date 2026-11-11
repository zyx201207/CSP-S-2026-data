#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
 int n,m,a;
 cin>>n>>m;
 for(int i=0;i<n;i++){
 	cin>>a;
 }
	srand(time(0));
	for(int i=0;i<m;i++){
		cout<<rand()%10<<" ";
	}
	
	return 0;
}
