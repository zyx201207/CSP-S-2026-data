#include<iostream>
using namespace std;
string a;
bool hwtest(string I,int start){
        for(int i=start;i<I.length()-start-1;i++){
                if(I[i]!=I[I.length()-i-1]) return false;
        }
        return true;
}
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int x;char c;
		cin >> x >> c;
		for(int j=1;j<=x;j++){
			a+=c;
		}
	}
	if(hwtest(a,0)) { 
		cout << 0;
		return 0;
	}
	for(int i=0;i<a.length();i++){
		if(hwtest(a,i)){
			cout << i;
			return 0;
		}
	}
	cout << a.length();
	return 0;
}
