#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
struct abc{
	int lg;
	char letter;
}word[N];
int n,l;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i<=n;i++){
		cin >> word[i].lg >> word[i].letter;
		l+=word[i].lg;
	}
	int i = 1,j = n;
	int x = word[i].lg,y = word[j].lg;
	int c = 0;
	while(i < j){
		if (word[i].letter == word[j].letter){
			if (x > y){
				x = x-y;
				j--;
				y = word[j].lg;
			}
			else if (x == y){
				i++;j--;
				x = word[i].lg;
				y = word[j].lg;
			}
			else if (x < y){
				y = y-x;
				i++;
				x = word[i].lg;
			}
		}
		else if (word[i].letter != word[j].letter){
			if (x > y){
				c += y;
				//cout << x-y <<endl;
				x = x-y;
				j--;
				y = word[j].lg;
			}
			else if (x == y){
				c += x;
				//cout << x <<endl;
				i++;j--;
				x = word[i].lg;
				y = word[j].lg;
			}
			else if (x < y){
				//cout << x <<endl;
				c += x;
				y = y-x;
				i++;
				x = word[i].lg;
			}
		}
	}
	cout << c;
	return 0;
}
