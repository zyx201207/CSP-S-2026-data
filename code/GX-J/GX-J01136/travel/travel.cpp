#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin ("travel.in");
    ofstream fout ("travel.out");

    int a;
    string B;
    int c;
    string D;
    int K = 0;
    int J = 0;


    fin >> a;
    fin >> B;
    fin >> c;
    fin >> D;

        string e[5] = {"01A","01B","01C","01D","01F"};
        string f[5] = {"02A","02B","02C","02D","02F"};
        string g[5] = {"03A","03B","03C","03D","03F"};
        string h[5] = {"04A","04B","04C","04D","04F"};
        string i[5] = {"05A","05B","05C","05D","05F"};
        string j[5] = {"06A","06B","06C","06D","06F"};
        string k[5] = {"07A","07B","07C","07D","07F"};
        string l[5] = {"08A","08B","08C","08D","08F"};
        string m[5] = {"09A","09B","09C","09D","09F"};
        string n[5] = {"10A","10B","10C","10D","10F"};
        string o[5] = {"11A","11B","11C","11D","11F"};
        string p[5] = {"12A","12B","12C","12D","12F"};
        string q[5] = {"13A","13B","13C","13D","13F"};
        string r[5] = {"14A","14B","14C","14D","14F"};
        string s[5] = {"15A","15B","15C","15D","15F"};
        string t[5] = {"16A","16B","16C","16D","16F"};
        string u[5] = {"17A","17B","17C","17D","17F"};
        string v[5] = {"18A","18B","18C","18D","18F"};

    if( a == c )
    {
        fout << '1' ;

        for(int O = 0; O < 18; O++)
        {

            if( (e + J)[I] == B )
            {

            }

        }
        else
        {
            J++;
        }



    }
    else
    {
        cout << '000';
        fout << '000';
    }




    fin.close();
    fout.close();
    return 0;
}
