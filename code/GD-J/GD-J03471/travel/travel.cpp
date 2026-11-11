#include<bits/stdc++.h>
using namespace std;

string cx1;
string cx2;
string zw1;
string zw2;
char a[100];
char b[100];
int x , y , k , m;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> cx1 >> zw1 >> cx2 >> zw2;
	
	for(int i = 0;i < zw1.size();i++){
		a[i] = zw1[i];
		b[i] = zw2[i];
	}
    
	if(cx1 == cx2){ 
    x = 1;
    }
	if(cx1 == cx2 && a[0] == b[0] && a[1] == b[1]){
	y = 1;
    }
	if(cx1 == cx2 && a[0] == b[0] && a[1] == b[1]){
	 if(a[2] == 'A' && b[2] == 'D') cout << 0;
		if(a[2] == 'A' && b[2] == 'F') k = 0;
		if(a[2] == 'B' && b[2] == 'D') k = 0;
		if(a[2] == 'F' && b[2] == 'F') k = 0;
		if(a[2] == 'C' && b[2] == 'D') k = 0;
		if(a[2] == 'C' && b[2] == 'D') k = 0;
	    else {
		k = 1;
	}
	}
	
    if(k == 1){
    if(a[2] == 'A' && b[2] == 'B') {
    	m = 1;
	}
    if(b[2] == 'A' && a[2] == 'B') {
    	m = 1;
	}
    if(a[2] == 'B' && b[2] == 'C') {
    	m = 1;
	}
    if(b[2] == 'B' && a[2] == 'C') {
    	m = 1;
	}
    if(a[2] == 'D' && b[2] == 'F') {
    	m = 1;
	}
    if(b[2] == 'D' && a[2] == 'F') {
	m = 1;
    }
	}
    cout << x << y << k << m;
	return 0;
}
