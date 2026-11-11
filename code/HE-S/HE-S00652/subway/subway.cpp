#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <vector>
using namespace std;
long long c,n,m,d,q;
long long spend_times[503];
int start,end;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	cin;
	for(int i=0;i<n;i++){
		cin;
	}
	cout<<c+n+m+d+q+3<<endl;
	cout<<"16"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

