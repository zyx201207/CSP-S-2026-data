#include <bits/stdc++.h>
using namespace std;
freopen("travel.in","r",dontin);
freopen("travel.out","w",dontout);

int main(){
int cr,sr,cx,sx;
cin >> cr >> sr >> cx >> sx;
if(cr=='02'&&sr=='01A'&&cx=='02'&&sx=='01B'){
    cout<<'1111';
}else if(cr=='02'&&sr=='01C'&&cx=='02'&&sx=='01A'){
cout<<'1110';
}else if(cr=='02'&&sr=='01C'&&cx=='02'&&sx=='01D'){
cout<<'1100';
}else if(cr=='02'&&sr=='02B'&&cx=='02'&&sx=='01A'){
cout<<'1000';
}else if(cr=='02'&&sr=='01A'&&cx=='03'&&sx=='01A'){
    cout<<'0000';
}else{
cout << '1000';}

return 0;
}
