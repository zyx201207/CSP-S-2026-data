#include<bits/stdc++.h>
using namespace std;
long long a[200005] = {0};
char b[200005] = {0};
long long shu = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int shu = 0;
	for(int i = 0;i < n;i++){
		long long l1;
		char l2;
		cin >> l1 >> l2;
		if(l2 == b[shu]){
			a[shu] += l1;
		}
		else{
			shu++;
			b[shu] = l2;
			a[shu] = l1;
		}
	}
	int ch = 0;
	for(int i = 0, j = 0;;){
		if(i >= shu-j){
			break;
		}
		if(b[i] == b[shu-j]){
			if(a[i] > a[shu-j]){
				a[i] -= a[shu-j];
				j++;
			}
			else if(a[i] < a[shu-j]){
				a[shu-j] -= a[i];
				i++;
			}
			else{
				i++;
				j++;
			}
		}
		else{
			if(a[i] > a[shu-j]){
				a[i] -= a[shu-j];
				ch += a[shu-j];
				j++;
			}
			else if(a[i] < a[shu-j]){
				a[shu-j] -= a[i];
				ch += a[i];
				i++;
			}
			else{
				ch += a[shu-j];
				i++;
				j++;
			}
		}
	}
	cout << ch;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
